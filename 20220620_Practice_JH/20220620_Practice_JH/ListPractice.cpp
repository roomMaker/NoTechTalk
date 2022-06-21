#include <list> // std::list�� ���� ���� ���
#include <iostream>

int main()
{
    std::list<int> list;

    // ����
    list.push_front(1); // push_front() : �� �տ� �����Ѵ�.
    // list{ 1 }
    list.push_back(2); // push_back() : �� �ڿ� �����Ѵ�.
    // list{ 1, 2 }
    list.insert(list.begin(), 9); // insert(pos, value) : pos ���� value�� �����Ѵ�.
    // list{ 9, 1, 2 }
    list.push_back(5); // list{ 9, 1, 2, 5 }

    // �ݺ���
    std::list<int>::iterator iter;
    iter = list.begin();
    // [9]<->[1]<->[2]<->[5]<->[ ]
    //  ��
    iter = list.end();
    // [9]<->[1]<->[2]<->[5]<->[ ]
    //                          ��
    std::list<int>::reverse_iterator riter;
    riter = list.rbegin();
    // [ ]<->[9]<->[1]<->[2]<->[5]
    //                          ��
    riter = list.rend();
    // [ ]<->[9]<->[1]<->[2]<->[5]
    //  ��

    // ����
    list.pop_front(); // pop_front() : ù ��° ���Ҹ� �����Ѵ�.
    // list{ 1, 2, 5 };
    list.pop_back(); // pop_back() : ������ ���� �����Ѵ�.
    // list{ 1, 2 };
    list.erase(list.begin()); // erase(pos) : pos�� �����Ѵ�.
    list.clear(); // clear() : �����̳ʸ� ���� ����.
    // list{ }

    // ũ��
    if (list.empty()) // empty() : ������� Ȯ���Ѵ�.
    {
        std::cout << "list�� �����.\n";
    }
    std::cout << "list.size() : " << list.size() << "\n";

    // �Ʒ�ó�� �ʱ�ȭ ����
    std::list<int> list2 = { 1, 2, 3, 4, 5 };

    // �б�
    std::cout << "list2.front() : " << list2.front() << "\n"; // front() : ù ��° ���Ҹ� ��ȯ�Ѵ�.
    std::cout << "list2.back() : " << list2.back() << "\n"; // back() : ������ ���Ҹ� ��ȯ�Ѵ�.

    // �� : �ٸ� �����̳ʿ� ���������� == / != / > / >= / < / <= ����
    list = list2;
    if (list == list2)
    {
        std::cout << "flist�� flist2�� ����.\n";
    }

    // C++17���ʹ� ���� Ÿ���� ���� �ʾƵ� �˾Ƽ� �߷��Ѵ�.
    std::list list3 = { 1, 2, 3, 4, 5 };

    return 0;
}
