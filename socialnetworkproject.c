#include<stdio.h>
#include<stdlib.h>
#define Max 100

typedef struct Node
{
    int data;
    struct Node*next;
}
Node;

typedef struct Queue
{
    int items [Max];
    int front, rear;
}
Queue;

Node*graph[Max];
int visited[Max];
Queue*createQueue()
{
    Queue*q = (Queue*)malloc(sizeof(Queue));
    q->front=-1;
    q->rear=-1;
    return q;
}

int isEmpty(Queue*q)
{
    return(q->rear==-1);
}

void enqueue (Queue*q, int value)
{
    if(q->rear==Max-1)
    return;
    if(q->front==-1)
    q->front=0;
    q->rear++;
    q->items[q->rear] = value; 
}

int dequeue(Queue*q)
{
    int item;
    if(isEmpty(q))return-1;
    item=q->items[q->front];
    q->front++;
    if(q->front > q->rear) q->front = q->rear = -1;
    return item;
}

void addEdge (int u, int v)
{
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->data=v;
    newNode->next=graph[u];
    graph[u]=newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data=u;
    newNode->next=graph[v];
    graph[v]=newNode;
}

void bfsRecommendations(int start, int n)
{
    Queue*q = createQueue();
    int level[Max] = {0};
    int friends[Max] = {0};
    int reco[Max] = {0};
    
    for(int i=0; i<n; i++)
    visited[i]=0;
    enqueue(q, start);
    visited[start]=1;
    level[start]=0;
    while(!isEmpty(q))
    {
       int cur = dequeue(q);
         Node*temp = graph[cur];
         
         while(temp!=NULL)
         {
            if(!visited[temp->data])
            {
                enqueue(q, temp->data);
                visited[temp->data]=1;
                level[temp->data]=level[cur]+1;
            }
            temp=temp->next;
         }
    }
    Node*temp = graph[start];
    while(temp!=NULL)
    {
        friends[temp->data]=1;
        temp=temp->next;
    }
    printf("Friend Recommendations for user %d:\n", start);
    int found = 0;
    for (int i=0; i<n; i++)
    {
        if(i==start) continue;
        if(level[i]==2 && !friends[i])
        {
            printf("User %d\n", i);
            found = 1;
        }
    }
    if(!found)
    printf("No recommendations found.\n");
    free(q);
}

int main()
{
    int n,m;
    printf("Enter the number of users (max%d): ", Max);
    scanf("%d", &n);

    if(n>Max) 
    n = Max;

    for(int i=0; i<n; i++)
    {
        graph[i] = NULL;
    }
    printf("Enter the number of conections: ");
    scanf("%d", &m);

    printf("Enter each connections as two user IDs(0to%d):\n", n-1);
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }

    int user;
    printf("Enter the user ID to get recommendations for: ");
    scanf("%d", &user);

    bfsRecommendations (user, n);
    for(int i=0; i<n; i++)
    {
        Node*temp = graph[i];
        while (temp)
        {
            Node*to_free = temp;
            temp = temp-> next;
            free(to_free);
        }

        }
        return 0;
    }



   