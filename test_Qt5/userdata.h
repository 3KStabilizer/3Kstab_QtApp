#ifndef USERDATA_H
#define USERDATA_H

/**
 * @brief represents the user data(the offset he has chosen for his stabilizer)
 */
class UserData
{
public:
    /**
     * @brief main constructor
     *
     */
    UserData();

    /**
     * @brief getter X
     *
     * @return int x
     */
    int getX();
    /**
     * @brief getter Y
     *
     * @return int y
     */
    int getY();
    /**
     * @brief getter Z
     *
     * @return int e
     */
    int getZ();

    /**
     * @brief setter x
     *
     * @param int new value of x
     */
    void setX(int);
    /**
     * @brief setter y
     *
     * @param int new value of y
     */
    void setY(int);
    /**
     * @brief setter z
     *
     * @param int new value of z
     */
    void setZ(int);

private:
    int x; /**< offstet in degree on X axis */
    int y; /**< offstet in degree on Y axis */
    int z; /**< offstet in degree on Z axis */
};

#endif // USERDATA_H
