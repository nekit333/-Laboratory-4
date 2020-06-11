#include "TwoWayQueue.h"

using namespace std;

int main()
{
    TwoWayQueue<int> q(3);
    q.print();

    q.pushBack(1);
    q.pushBack(2);
    q.pushFront(0);
    q.print();

    q.popFront(3);
    q.print();

    TwoWayQueue<char> q1(3);
    q1.pushBack('V');
    q1.pushBack('G');
    q1.pushBack('A');
    q1.print();
    return 0;
}
