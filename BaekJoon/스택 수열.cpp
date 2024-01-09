#include <iostream>

/*
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다.
스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.
1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 
이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 
임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 
있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다.
이를 계산하는 프로그램을 작성하라.


첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다.
둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 
물론 같은 정수가 두 번 나오는 일은 없다.
*/

using namespace std;

class Stack {
private:
    int* data;
    size_t N;
    int pos;
public:
    Stack();
    Stack(int n);
    ~Stack();
    
    int top();
    int pop();
    int size();
    int getPos();
    void push(int num);
    bool empty();
    bool full();
};

Stack::Stack() {
    pos = -1;
    N = 10;
    this->data = new int[10];
}

Stack::Stack(int n){
    pos = -1;
    N = n;
    this->data = new int[n];
}

Stack::~Stack() {
    delete[] this->data;
}

int Stack::pop() {
    if (!this->empty())
        return data[pos--];
    else
        return -1;
}

int Stack::top() {
    if (!this->empty())
        return data[pos];
    return -1;
}

void Stack::push(int num) {
    if(!this->full())
    data[++pos] = num;
}

int Stack::size() {
    return this->pos+1;
}

int Stack::getPos() {
    return pos;
}
 
bool Stack::full() {
    if (pos == N)
        return true;
    else
        return false;
}

bool Stack::empty() {
    if (pos == -1) 
        return true;
    else 
        return false;
}

int main(){
    int n;
    int tmp = 1;
    bool idx = false;
    cin >> n;
    Stack stack(n);
    int num;
    string str = "";

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        while (num > stack.top())
        {
            stack.push(tmp++);
            str += "+";
        }

        if (stack.top() == num)
        {
            stack.pop();
            str += "-";
        } 
        else
        {
            idx = true;
            break;
        }

    }

    if (idx)
        cout << "NO";
    else {
        for (int i = 0; i < str.length(); i++)
            cout << str[i] << "\n";
    }

    return 0;
}
