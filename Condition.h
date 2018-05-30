#ifndef THOR_CONDITION_H
#define THOR_CONDITION_H
#include <NonCopyable.h>
#include <Mutex.h>
#include <ThorAssert.h>

namespace thor{
    class Condition : public NonCopyable{
        public:
            explicit Condition(MutexLock &mutex):
                mutex_(mutex){
                    THOR_ASSERT(pthread_cond_init(&cond_, nullptr) == 0);
            }
            ~Condition(){
                pthread_cond_destroy(&cond_);
            }
            void wait(){
                mutex_.unAssignHolder();
                THOR_ASSERT(pthread_cond_wait(&cond_, mutex_.getPthreadMutex()) == 0);
            }
            void notify() {
                THOR_ASSERT(pthread_cond_signal(&cond_) == 0);
            }
            void notifyAll(){
                THOR_ASSERT(pthread_cond_broadcast(&cond_));
            }
        private:
            pthread_cond_t cond_;
            MutexLock &mutex_;
    };
}
#endif //THOR_CONDITION_H
