🚀 Friend Recommendation System (C + BFS)








📖 Overview

This project implements a Friend Recommendation System using Graph Data Structure and Breadth-First Search (BFS) in C.

Users are represented as nodes and friendships as edges. The system suggests new connections based on friends-of-friends (level 2 connections) — similar to real-world social platforms.

✨ Features
🔗 Graph using Adjacency List (Linked List)
🔍 Efficient BFS Traversal
👥 Recommends friends of friends
🚫 Filters out:
The user themselves
Existing direct friends
🧠 Concepts Used
Graph Data Structure
Breadth-First Search (BFS)
Queue (Array Implementation)
Linked List
⚙️ How It Works
Build a graph from user connections
Perform BFS from the target user
Track levels (distance from source)
Extract users at level 2
Filter direct friends
Display recommendations
🖥️ Example
🔹 Input
Enter the number of users: 5
Enter the number of connections: 4
Connections:
0 1
0 2
1 3
2 4
Enter user: 0
🔹 Output
Friend Recommendations for user 0:
User 3
User 4
📌 Limitations
❌ No ranking of recommendations
❌ No personalization (interests/activity not considered)
❌ Fixed size (Max = 100)
🚀 Future Improvements
⭐ Rank users based on mutual friends
📊 Add scoring system for better recommendations
🔄 Use dynamic memory allocation
🤖 Integrate AI/ML-based recommendation logic
🛠️ How to Run
gcc program.c -o program
./program
📂 Project Structure
.
├── program.c
└── README.md
🏁 Conclusion

This project shows how graph algorithms like BFS can solve real-world problems such as social network recommendations efficiently.

👩‍💻 Author

Noor
B.Tech Computer Engineering Student 🚀
