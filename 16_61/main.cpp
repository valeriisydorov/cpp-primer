#include <memory>
#include <utility>

template <typename T, typename... Args> std::shared_ptr<T> makeShared(Args&&... args) {
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {
    return 0;
}
