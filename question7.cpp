#include <iostream>
using namespace std;

class PlaylistManager
{
private:
    int **a;
    int *sz;
    int n;

    bool check(int p) const
    {
        if (p < 0 || p >= n)
        {
            cout << "Error: Playlist index out of bounds!\n";
            return false;
        }
        return true;
    }

public:
    PlaylistManager(int cnt, const int s[])
    {
        n = cnt > 0 ? cnt : 0;
        a = new int *[n];
        sz = new int[n];
        for (int p = 0; p < n; p++)
        {
            sz[p] = s[p] > 0 ? s[p] : 0;
            a[p] = new int[sz[p]];
            for (int t = 0; t < sz[p]; t++)
                a[p][t] = 0;
        }
    }

    PlaylistManager(const PlaylistManager &obj)
    {
        n = obj.n;
        a = new int *[n];
        sz = new int[n];
        for (int p = 0; p < n; p++)
        {
            sz[p] = obj.sz[p];
            a[p] = new int[sz[p]];
            for (int t = 0; t < sz[p]; t++)
            {
                a[p][t] = obj.a[p][t];
            }
        }
    }

    PlaylistManager &operator=(const PlaylistManager &obj)
    {
        if (this == &obj)
            return *this;
        PlaylistManager tmp(obj);

        int **b = a;
        int *cap = sz;
        int cnt = n;
        a = tmp.a;
        sz = tmp.sz;
        n = tmp.n;
        tmp.a = b;
        tmp.sz = cap;
        tmp.n = cnt;
        return *this;
    }

    ~PlaylistManager()
    {
        for (int p = 0; p < n; p++)
            delete[] a[p];
        delete[] a;
        delete[] sz;
    }

    void setTrack(int p, int t, int id)
    {
        if (!check(p))
            return;
        if (t < 0 || t >= sz[p])
        {
            cout << "Error: Track index out of bounds!\n";
            return;
        }
        a[p][t] = id;
    }

    void addTrack(int p, int id)
    {
        if (!check(p))
            return;
        int len = sz[p];
        int *tmp = new int[len + 1];
        for (int t = 0; t < len; t++)
            tmp[t] = a[p][t];
        tmp[len] = id;
        delete[] a[p];
        a[p] = tmp;
        sz[p] = len + 1;
        cout << "Playlist " << p << " resized: " << len << " -> " << len + 1 << '\n';
    }

    void playTrack(int p, int t) const
    {
        if (!check(p))
            return;
        if (t < 0 || t >= sz[p])
        {
            cout << "Error: Track index out of bounds!\n";
            return;
        }
        cout << "Playing track ID " << a[p][t] << '\n';
    }

    void show() const
    {
        for (int p = 0; p < n; p++)
        {
            cout << "Playlist " << p << " (" << sz[p] << " tracks): ";
            for (int t = 0; t < sz[p]; t++)
                cout << a[p][t] << ' ';
            cout << '\n';
        }
    }
};

int main()
{
    int s[3] = {2, 3, 1};
    PlaylistManager p1(3, s);
    p1.setTrack(0, 0, 101);
    p1.setTrack(0, 1, 102);
    p1.setTrack(1, 0, 201);
    p1.setTrack(1, 1, 202);
    p1.setTrack(1, 2, 203);
    p1.setTrack(2, 0, 301);

    PlaylistManager p2(p1);
    cout << "Deep-copy archive created.\n";
    p2.setTrack(0, 0, 999);
    p2.addTrack(1, 204);

    cout << "\nOriginal (unchanged):\n";
    p1.show();
    cout << "\nArchive (modified independently):\n";
    p2.show();

    cout << "\nPlayback and bounds validation:\n";
    p2.playTrack(1, 3);
    p2.playTrack(3, 0);
    p2.playTrack(0, 2);
    p2.playTrack(-1, 0);
    p2.playTrack(0, -1);

    PlaylistManager p3(3, s);
    p3 = p1;
    p3.setTrack(2, 0, 888);
    cout << "\nAssigned copy (modified independently):\n";
    p3.show();
    cout << "Original playlist 2 still contains: ";
    p1.playTrack(2, 0);
    return 0;
}
