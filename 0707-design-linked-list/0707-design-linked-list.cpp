struct DNode
{
    int val;
    DNode* prev;
    DNode* next;
    DNode(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class MyLinkedList
{
    DNode* head;
    DNode* tail;
    int count;

public:
    MyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    int get(int index)
    {
        int ct = 0;
        DNode* temp = head;
        while (temp != nullptr)
        {
            if (ct == index)
            {
                return temp->val;
            }
            temp = temp->next;
            ct++;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        DNode* temp = new DNode(val);
        if (count == 0)
        {
            head = tail = temp;
            count++;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
        count++;
    }

    void addAtTail(int val)
    {
        DNode* temp = new DNode(val);
        if (count == 0)
        {
            head = tail = temp;
            count++;
            return;
        }
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        count++;
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == count)
        {
            addAtTail(val);
            return;
        }
        if (index >= count)
        {
            return;
        }
        int ct = 0;
        DNode* temp = head;
        while (temp != nullptr)
        {
            ct++;
            if (ct == index)
            {
                DNode* v = new DNode(val);
                DNode* t = temp->next;
                temp->next = v;
                v->next = t;
                t->prev = v;
                v->prev = temp;
                count++;
                return;
            }
            temp = temp->next;
        }
    }

    void deleteAtIndex(int index)
    {
        if (count == 0||index >= count)
        {
            return;
        }
         if (index == 0)
        {
            DNode* t = head;
            head = head->next;
            if (head){
                head->prev = nullptr;
            }
            else{
                tail = nullptr;
        }
        delete t;
        count--;
        return;
        }
        if (index == count - 1)
        {
            DNode* t = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete t;
            count--;
            return;
        }
        int ct = 0;
        DNode* temp = head;
        while (temp != nullptr)
        {
            ct++;
            if (ct == index)
            {
                DNode* t = temp->next;
                temp->next = temp->next->next;
                t->next->prev = temp;
                delete t;
                count--;
                return;
            }
            temp = temp->next;
        }
    }
};