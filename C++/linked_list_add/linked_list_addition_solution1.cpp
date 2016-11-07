#include <iostream>
using namespace std;

struct linked_list
{
    int num;
    struct linked_list *next;
};

int getLength(struct linked_list *head)
{
    int len=0;
    linked_list *temp = head;
    while(temp)
    {
        len++;
        temp = temp->next;
    }
    return(len);
}

int digit_sum(struct linked_list *list1, struct linked_list *list2, int l1, int l2, int digit_num)
{
    int num1=0, num2=0;
    if(l1>=digit_num)
    {
        while(l1>digit_num) {
            l1--;
            list1=list1->next;
        }
        num1=list1->num;
    }
    if(l2>=digit_num)
    {
        while(l2>digit_num) {
            l2--;
            list2=list2->next;
        }
        num2=list2->num;
    }
    return(num1+ num2);
}

struct linked_list *add_list(struct linked_list *list1, struct linked_list *list2)
{
    struct linked_list *list3;
    struct linked_list *head3 = NULL;
    int sum, carry=0, l1, l2;
    l1 = getLength(list1);
    l2 = getLength(list2);
    int digit_num=1, max=0;
    if(l1>l2) {
        max=l1;
    }
    else {
        max=l2;
    }
    while(digit_num<=max) {
        sum=digit_sum(list1, list2, l1, l2, digit_num);
        sum=sum+carry;
        list3=new linked_list;
        list3->num=sum%10;
        carry=sum/10;
        list3->next=head3;
        head3=list3;
        digit_num++;
    }
    
    if(carry>0) {
        struct linked_list *temp = new linked_list;
        temp->num=carry;
        temp->next=head3;
        head3=temp;
    }
    return head3;
}

int main() {
	struct linked_list *head1=NULL;
	struct linked_list *ll1=new linked_list;
	ll1->num=9;
	ll1->next=head1;
	head1 = ll1;
	ll1=new linked_list;
	ll1->num=8;
	ll1->next = head1;
	head1=ll1;
	ll1=new linked_list;
	ll1->num=9;
	ll1->next=head1;
	head1=ll1;
	ll1=new linked_list;
	ll1->num=9;
	ll1->next=head1;
	head1=ll1;
	head1=head1->next;
	
	struct linked_list *head2=NULL;
	struct linked_list *ll2=new linked_list;
	ll2->num=1;
	ll2->next=head2;
	head2=ll2;
	ll2=new linked_list;
	ll2->num=1;
	ll2->next=head2;
	head2=ll2;
	ll2=new linked_list;
	ll2->num=1;
	ll2->next=head2;
	head2=ll2;
	struct linked_list *ll3=add_list(ll1, ll2);
	while(ll3)
	{
	    cout<<ll3->num;
	    ll3=ll3->next;
	}
	return(0);
}
