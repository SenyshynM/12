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
void enqueue(Elem*& first, Elem*& last, Info k, Info numb);
void dequeue(Elem*& first, Elem*& last);
int count(Elem* first, int k);

int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;
    
    enqueue(first, last, 1, 10);

    cout << "Кількість від'ємних елментів: " << count(first, 0) << endl;


    dequeue(first, last);
}

void enqueue(Elem*& first, Elem*& last, Info k, Info numb)
{
    Info value = -10 + rand() % 20; 
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
    if (k < numb) {
        k++;
        enqueue(first, last, k, numb);
    }
}

void dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL;
    cout << value << " ";
    if (last != NULL) {
        dequeue(first, last);
    }
}

int count(Elem* first, int k) {
    if (first != NULL) {
        if (first->info < 0) {
            k++;
            count(first->next, k);
        }
        else
            count(first->next, k);
    }
    else
        return k;
}
