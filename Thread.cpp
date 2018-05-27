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
    void* realThreadFunctor(void*) {

    }
}
Thread::Thread(const std::function<void(void)> &func) :
    func_(func), running_(false){
}

void Thread::start(){
    THOR_ASSERT(!running_);
    running_ = true;
    int ret = pthread_create(&pthreadId_, nullptr, )
}