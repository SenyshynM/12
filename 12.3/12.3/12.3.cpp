// варіант 19 -- без зірочки

#include <iostream>
#include <Windows.h>
#include <time.h>

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

using namespace std;
void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
int count(Elem* first);

int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;
    for (int i = 1; i <= 3; i++) {
        Info numb = -10 + rand() % 20;
        enqueue(first, last, numb);
    }

    cout << "Кількість від'ємних елментів: " << count(first);
    cout << endl;

    while (last != NULL) {
        cout << dequeue(first, last) << " ";
    }
    cout << endl << endl;
}

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL;
    return value;
}

int count(Elem* first) {
    int k = 0;
    while (first != NULL) {
        if (first->info < 0) {
            k++;
            first = first->next;
        }
        else
            first = first->next;
    }
    return k;
}
