class RideSharingSystem
{
    vector<int> rID;
    vector<int> dID;

public:
    RideSharingSystem()
    {
        // TODO
    }

    void addRider(int riderId)
    {
        int s = rID.size();
        for (int i = 0; i < s; i++)
        {
            if (rID[i] == riderId)
            {
                return;
            }
        }
        rID.push_back(riderId);
    }

    void addDriver(int driverId)
    {
        int s = dID.size();
        for (int i = 0; i < s; i++)
        {
            if (dID[i] == driverId)
            {
                return;
            }
        }
        dID.push_back(driverId);
    }

    vector<int> matchDriverWithRider()
    {
        if (dID.empty() || rID.empty())
            return {-1, -1};

        int d = dID[0];
        dID.erase(dID.begin());

        int r = rID[0];
        rID.erase(rID.begin());

        return {d, r};
    }

    void cancelRider(int riderId)
    {
        int s = rID.size();
        for (int i = 0; i < s; i++)
        {
            if (rID[i] == riderId)
            {
                rID.erase(rID.begin() + i);
                return;
            }
        }
    }
};