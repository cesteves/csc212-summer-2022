class Node{
    private:
        int data;
        int priority;
        Node* next;

    public:
        // Not used. Implemented anyway.
        Node();
        Node(int data, int priority);
        Node(int data, int priority, Node* next);

        friend class PQueue;
};