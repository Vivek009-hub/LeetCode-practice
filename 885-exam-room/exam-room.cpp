
class ExamRoom {
private:
    int n;
    set<int> occupied;

public:
    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        if (occupied.empty()) {
            occupied.insert(0);
            return 0;
        }

        int bestSeat = 0;
        int maxDist = *occupied.begin();

        auto prev = occupied.begin();

        for (auto it = next(prev); it != occupied.end(); it++) {
            int dist = (*it - *prev) / 2;

            if (dist > maxDist) {
                maxDist = dist;
                bestSeat = *prev + dist;
            }

            prev = it;
        }

        int lastDist = n - 1 - *occupied.rbegin();

        if (lastDist > maxDist) {
            bestSeat = n - 1;
        }

        occupied.insert(bestSeat);
        return bestSeat;
    }

    void leave(int p) {
        occupied.erase(p);
    }
};
