void enqueue(string data)
{
    s.push();
}

void dequeue()
{ 
    assert(!empty());
    if(!s2.empty) s2.pop();
    else
    {
        while(!s1.empty)
        {
            s2.push(s1.peek());
            s1.pop();
        }
    }
    s2.pop();
}

string getFront()
{
    s2.peek();
}

int getSize()
{
    return s1.size + s2.size;
}

bool emppty()
{
    return s1.empty() && s2.empty();
}

void print()
{
    print();
    reverseprint();
}

reversePrint(Node* node)
{
    assert(!empty());
    Node* temp = node;
    if( == NULL) return;
    else
    {
        
    }
}