#include <forward_list>

void npmInstall()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    int N;

    cin >> T >> N;

    int current;
    std::forward_list<int> l;

    for (int i = 0; i < T; i++)
    {
        cin >> current;

        auto target = std::find(l.begin(), l.end(), current);
        if (target != l.end())
        {
            l.insert_after(l.end(), current);

            auto prev = l.before_begin();  // Start before the first element
            for (auto it = l.begin(); it != target; ++it) {
                prev = it;  // Update prev to be one step behind it
            }

            if (target != l.end()) {
                // Bypass the currentIterator by setting prevIterator's next to currentIterator's next
                prev = l.insert_after(prev, *std::next(target));
                l.erase_after(target);
            }


            std::cout << true;
        }
        else
        {
            int length = std::distance(l.begin(), l.end());
            if (length >= N)
                l.pop_front();

            l.insert_after(l.end(), current);

            std::cout << false;
        }
    }

}