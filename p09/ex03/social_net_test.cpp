#include <iostream>
#include <vector>
#include "social_net.cpp"

using namespace std;

int main()
{
    SocialNetwork network2(6); // 6 people in the social network

    // Add friendships
    network2.addFriendship(0, 1);
    network2.addFriendship(0, 2);
    network2.addFriendship(1, 2);
    network2.addFriendship(1, 3);
    network2.addFriendship(2, 4);
    network2.addFriendship(3, 4);
    network2.addFriendship(4, 5);

    network2.printSocialNetwork();

    // Find mutual friends between person 0 and person 1
    network2.findMutualFriends(0, 1);
    network2.findMutualFriends(2, 3);
    network2.findMutualFriends(1, 4);

    SocialNetwork network1(6); // 6 people in the social network

    // Add friendships
    network1.addFriendship(0, 1);
    network1.addFriendship(0, 2);
    network1.addFriendship(1, 2);
    network1.addFriendship(3, 4);
    network1.addFriendship(4, 5);

    network1.findConnectedGroups();

    return 0;
}