#ifndef PLAYER_H
#define PLAYER_H


class player
{
    public:
        player();
        virtual ~player();
        player(const player& other);

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }

    protected:

    private:
        unsigned int m_Counter;
};

#endif // PLAYER_H
