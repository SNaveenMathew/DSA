#include <iostream>
using namespace std;

struct linked_list
{
    int num;
    struct linked_list *next;
};

int getNumber(struct linked_list *head)
{
    int num=0;
    while(head)
    {
        num*=10;
        num=num+head->num;
        head = head->next;
    }
    return(num);
}

struct linked_list *represent_as_ll(int num)
{
    struct linked_list *head1=NULL;
	struct linked_list *ll1;
	while(num>0)
	{
	    ll1=new linked_list;
	    ll1->num=num%10;
	    num/=10;
	    ll1->next=head1;
	    head1 = ll1;
	}
	return(head1);
}

int main() {
	struct linked_list *head1=represent_as_ll(1889);
	struct linked_list *head2=represent_as_ll(11);
	int num1 = getNumber(head1), num2 = getNumber(head2);
	int num3 = num1+num2;
	struct linked_list *head3=represent_as_ll(num3);
	while(head3)
	{
	    cout<<head3->num;
	    head3=head3->next;
	}
	return(0);
}
