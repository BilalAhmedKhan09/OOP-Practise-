#include <iostream>
#include <string>

using namespace std;

class PlaylistManager {
private:
    string songs[100];
    int songCount = 0;
    string currentTrack = "";

public:

    void addToPlaylist(string track) {
        if (songCount < 100) {
            songs[songCount] = track;
            songCount++;
            cout << "Track '" << track << "' added to the playlist." << endl;
        } else {
            cout << "The playlist is full! Cannot add more tracks." << endl;
        }
    }

    void removeFromPlaylist(string track) {
        bool found = false;
        for (int i = 0; i < songCount; ++i) {
            if (songs[i] == track) {
                for (int j = i; j < songCount - 1; ++j) {
                    songs[j] = songs[j + 1];
                }
                songCount--;
                found = true;
                cout << "Track '" << track << "' removed from the playlist." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Track '" << track << "' not found in the playlist." << endl;
        }
    }

    void playTrack(string track) {
        bool found = false;
        for (int i = 0; i < songCount; ++i) {
            if (songs[i] == track) {
                currentTrack = track;
                cout << "Now playing: '" << track << "'" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Track '" << track << "' not found in the playlist." << endl;
        }
    }

    void showPlaylist() {
        if (songCount == 0) {
            cout << "Your playlist is empty." << endl;
            return;
        }

        cout << "Your Playlist:" << endl;
        for (int i = 0; i < songCount; ++i) {
            cout << songs[i] << endl;
        }
    }
};

int main() {
    PlaylistManager myPlaylist;

    myPlaylist.addToPlaylist("Uptown Funk");
    myPlaylist.addToPlaylist("Happy");
    myPlaylist.addToPlaylist("Bad Guy");
    myPlaylist.addToPlaylist("Shallow");

    myPlaylist.showPlaylist();

    myPlaylist.playTrack("Bad Guy");
    myPlaylist.removeFromPlaylist("Happy");

    myPlaylist.showPlaylist();

    myPlaylist.playTrack("Happy");

    return 0;
}
