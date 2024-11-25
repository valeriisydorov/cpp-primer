#include <vector>
using std::vector;

class Matrix
{
    public:
        virtual ~Matrix() {};
        virtual void method() = 0;
};

bool compare(const Matrix &, const Matrix &);

vector<int>::iterator change_val(const int &, vector<int>::iterator &);

int main() {
    return 0;
}
