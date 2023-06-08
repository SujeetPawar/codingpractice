#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char label[10];
    int ch_count;
    struct node *child[10];
} *root;

class GT
{
public:
    void create_tree();
    void display(node *r);
    GT()
    {
        root = NULL;
    }
};
void GT ::create_tree()
{
    int tbooks, tchapter, i, j, k;
    root = new node;
    cout << "Enter the name of book:- " << endl;
    cin >> root->label;
    cout << "Enter no.of chapters in book: - " << endl;
    cin >> tchapter;
    root->ch_count = tchapter;
    for (i = 0; i < tchapter; i++)
    {
        root->child[i] = new node;
        cout << "Enter chapter name "<<i+1<< ":- " << endl;
        cin >> root->child[i]->label;
        cout << "Enter no. of section in chapter " << root->child[i]->label << ":-";
        cin >> root->child[i]->ch_count;
        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter section " << j + 1 << " name\n";
            cin >> root->child[i]->child[j]->label;
            cout << "Enter no. of sub-sections in " << root->child[i]->child[j]->label << ":-";
            cin >> root->child[i]->child[j]->ch_count;
            for (k = 0; k < root->child[i]->child[j]->ch_count; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "Enter subsection " << k + 1 << " name\n";
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void GT::display(node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n---Book Ladder---" << endl;
        tchapters = r1->ch_count;
        cout << "\n---Chapter---" << endl;
        for (i = 0; i < tchapters; i++)
        {
            cout << "\n Chapter " << i + 1 << " " << r1->child[i]->label;
            cout << "\n Sections:- " << endl;
            for (j = 0; j < r1->child[i]->ch_count; i++)
            {
                cout << r1->child[i]->label;
                cout << "\n Sub-sections:- " << endl;
                for (k = 0; k < r1->child[i]->child[j]->ch_count; k++)
                {
                    cout << r1->child[i]->child[j]->child[k]->label<<endl;
                }
            }
        }
    }
}
int main()
{
    int choice;
    GT gt;
    while (1)
    {
        cout << "----------" << endl;
        cout << "Book Tree Collection" << endl;
        cout << "-----------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;
        case 2:
            gt.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}