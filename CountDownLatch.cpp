#include <CountDownLatch.h>
using namespace thor;

CountDownLatch::CountDownLatch(const int count):
    count_(count), condition_(lock_){
}

int CountDownLatch::getCount() const {
    MutexLockGuard guard(lock_);
    return count_;
}

void CountDownLatch::countDown() {
    MutexLockGuard guard(lock_);
    --count_;
    if(count_ == 0) {
        condition_.notifyAll();
    }
}

void CountDownLatch::wait() {
    MutexLockGuard guard(lock_);
    while(count_>0) {
        condition_.wait();
    }
}