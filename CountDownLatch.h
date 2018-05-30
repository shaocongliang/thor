#ifndef THOR_COUNTDOWN_LATCH_H
#define THOR_COUNTDOWN_LATCH_H
#include <NonCopyable.h>
#include <Mutex.h>
#include <Condition.h>
namespace thor{
    class CountDownLatch : public NonCopyable{
        public:
            explicit CountDownLatch(const int count);
            ~CountDownLatch();
            void countDown();
            void wait();
            int getCount() const;
        private:
            int count_;
            mutable MutexLock lock_;
            Condition condition_;            
    };
}
#endif