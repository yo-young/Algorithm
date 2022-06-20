#include<iostream>
#include<memory>
using namespace std;

int main()
{
    //1. unique_ptr
	auto ptr1 = std::make_unique<int>(1);
	cout << *ptr1 << endl;

    unique_ptr<int> ptr2 = move(ptr1);

	if (!ptr1)
	{
		std::cout << "ptr1 is empty" << std::endl;
	}

    //2.share_ptr
    auto ptr3 = std::make_shared<int>(11);
    cout << ptr3.use_count() << endl;
    shared_ptr<int> ptr4 = ptr3;
    cout << ptr3.use_count() << endl;
    ptr4.reset();
    cout << ptr3.use_count() << endl;
    weak_ptr<int> ptr5 = ptr3;
    cout << ptr3.use_count() << endl;

	return 0;
}