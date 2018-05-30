#ifndef THOR_MUTEX_H
#define THOR_MUTEX_H
#include <unistd.h>
#include <pthread.h>

#include <Thread.h>
#include <ThorAssert.h>
#include <NonCopyable.h>
namespace thor {
class MutexLock : public NonCopyable {
 public:
  MutexLock() : holder_(0) {
    THOR_ASSERT(pthread_mutex_init(&mutex_, nullptr) == 0);
  }
  bool isLockedByThisThread() const {
    return holder_ == getThreadId();
  }
  void lock() {
    THOR_ASSERT(pthread_mutex_lock(&mutex_) == 0);
    assignHolder();
  }
  void unlock() {
    THOR_ASSERT(pthread_mutex_unlock(&mutex_)==0);
    unAssignHolder();
  }
  pthread_mutex_t* getPthreadMutex(){
    return &mutex_;
  }
 private:
 friend class Condition;
  void assignHolder() {
    holder_ == getThreadId();
  }
  void unAssignHolder() {
    holder_ = 0;
  }
  pid_t holder_;
  pthread_mutex_t mutex_;
};

class MutexLockGuard : public NonCopyable{
 public:
  explicit MutexLockGuard(MutexLock &lock):lock_(lock){
    lock_.lock();
  }
  ~MutexLockGuard(){
    lock_.unlock();
  }
 private:
  MutexLock &lock_;
};

#define MutexLockGuard(x) error "Invalid usage"
}
#endif