#include <iostream>
#include <string>

using namespace std;

class User; 

class Comment {
    int commentID;
    string content;
    User* author;

public:
    Comment(int id = 0, string c = "", User* u = nullptr) : commentID(id), content(c), author(u) {}

    void display() const;
};

class Post {
    int postID;
    string content;
    Comment* comments[3];
    int commentCount;

public:
    Post(int id = 0, string c = "") : postID(id), content(c), commentCount(0) {
        for (int i = 0; i < 3; i++) {
            comments[i] = nullptr;
        }
    }

    void addComment(Comment* comm) {
        if (commentCount < 3) {
            comments[commentCount++] = comm;
        } else {
            cout << "Cannot add more comments. Maximum limit reached!\n";
        }
    }

    void display() const {
        cout << "Post [" << postID << "]: " << content << "\n";
        for (int i = 0; i < commentCount; i++) {
            comments[i]->display();
        }
    }
};

class User {
    int userID;
    string username;
    Post* posts[3];
    int postCount;

public:
    User(int id = 0, string name = "") : userID(id), username(name), postCount(0) {
        for (int j = 0; j < 3; j++) {
            posts[j] = nullptr;
        }
    }

    void addPost(Post* p) {
        if (postCount < 3) {
            posts[postCount++] = p;
        } else {
            cout << "Cannot create more posts. Maximum limit reached!\n";
        }
    }

    void displayFeed() const {
        cout << "User: " << username << " (ID: " << userID << ")\n";
        cout << "Posts:\n";
        for (int i = 0; i < postCount; i++) {
            posts[i]->display();
        }
    }
    string getname(){
        return username;
    }
};

void Comment::display() const {
    cout << "  - Comment [" << commentID << "]: " << content;
    if (author) {
        cout << " (by " << author->getname() << ")";
    }
    cout << "\n";
}

int main() {
    User* user1 = new User(1, "Alice");
    User* user2 = new User(2, "Bob");

    Post* post1 = new Post(100, "Hello, this is Alice's first post!");
    Post* post2 = new Post(101, "Bob's thoughts on C++.");

    user1->addPost(post1);
    user2->addPost(post2);

    Comment* comment1 = new Comment(200, "Nice post, Alice!", user2);
    Comment* comment2 = new Comment(201, "Thanks for sharing, Bob!", user1);

    post1->addComment(comment1);
    post2->addComment(comment2);

    cout << "\n--- Alice's Feed ---\n";
    user1->displayFeed();
    
    cout << "\n--- Bob's Feed ---\n";
    user2->displayFeed();

    delete comment1;
    delete comment2;
    delete post1;
    delete post2;
    delete user1;
    delete user2;
}
