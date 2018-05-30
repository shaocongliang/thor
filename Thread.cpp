#include <sys/types.h>
#include <pthread.h>
#include "ThorAssert.h"
#include "Thread.h"

namespace thor{
    pid_t getThreadId(){
        return pthread_mach_thread_np(pthread_self());
    }
}
using namespace thor;

namespace detail{
    struct ThreadData{
        ThreadData(const ThreadFunc &func, const std::string &name, pid_t *tid):
            func_(func), name_(name), ptid_(tid){
            }
        ThreadFunc func_;
        std::string name_;
        pid_t *ptid_;
        void run(void);
    };
    void* realThreadFunctor(void *p) {
       ThreadData *pthr = static_cast<ThreadData*>(p);
    }
}
Thread::Thread(const std::function<void(void)> &func) :
    func_(func), running_(false){
}
void Thread::start(){
    THOR_ASSERT(!running_);
    running_ = true;
    detail::ThreadData *pthrdat = new detail::ThreadData(func_, name_, &tid_);
    int ret = pthread_create(&pthreadId_, nullptr, &detail::realThreadFunctor, &pthrdat);
    if(ret) {
       delete pthrdat; 
    }
}