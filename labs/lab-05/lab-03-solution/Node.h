class Node{
    private:
        int data;
        Node* next;

    public:
        // Not used. Implemented anyway.
        Node();
        Node(int data);
        Node(int data, Node* next);

        friend class LinkedList;
};