#ifndef THOR_NONCOPYABLE_H
#define THOR_NONCOPYABLE_H
namespace thor{
    class NonCopyable{
        public:
        NonCopyable() = default;
        NonCopyable(const NonCopyable &rhs) = delete;
        NonCopyable& operator=(const NonCopyable &rhs) = delete;
    };
}
#endif // !1THOR_NONCOPYABLE_H