#include <iostream>
#include

using namespace std;

int main()
{
    struct person
    {
        int no;
        char name[10];
        float salary;
        struct person *next;
    };
    struct person a, b, c, *head, *p;
    scanf("%d", a.no);
    scanf("%s", a.name);
    scanf("%f", a.salary);

    scanf("%d", b.no);
    scanf("%s", b.name);
    scanf("%f", b.salary);

    scanf("%d", c.no);
    scanf("%s", c.name);
    scanf("%f", c.salary);

    /* 2 */
    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    for( p = head; p != NULL;p = p.next){
        printf("%d ", p->no);
        printf("%s ", p->name);
        printf("%f\n", p->salary);
    }

    return 0;
}
