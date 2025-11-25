/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue
{
public:
    MyCircularQueue(int k)
    {
        data = new int[k];
        capcity = k;
    }

    ~MyCircularQueue() {
        delete [] data;
    }

    bool enQueue(int value)
    {
        if (size >= capcity)
        {
            return false;
        }

        if (size == 0)
        {
            data[rear] = value;
        }
        else
        {
            if (rear < capcity - 1)
            {
                data[++rear] = value;
            }
            else
            {
                rear = 0;
                data[rear] = value;
            }
        }

        size++;
        return true;
    }

    bool deQueue()
    {
        if (size == 0)
        {
            return false;
        }

        if (size > 1)
        {
            if (front < capcity - 1)
            {
                front++;
            }
            else
            {
                front = 0;
            }
        }
        size--;
        return true;
    }

    int Front()
    {
        if (size == 0)
        {
            return -1;
        }

        return data[front];
    }

    int Rear()
    {
        if (size == 0)
        {
            return -1;
        }

        return data[rear];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capcity;
    }

private:
    int *data;
    int rear = 0, front = 0;
    int size = 0, capcity = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
