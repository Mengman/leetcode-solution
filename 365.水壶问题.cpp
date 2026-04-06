/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution
{
public:
    bool canMeasureWater(int x, int y, int target)
    {
        return bezoutsIdentity(x, y, target);
    }

    bool bezoutsIdentity(int x, int y, int target)
    {
        // 满足 ax + by = target
        // 要求:
        //  1. x + y >= target
        //  2. target % 最大公约数gcd(x, y) == 0
        if (x + y < target)
            return false;

        if (x == 0 || y == 0)
        {
            return target == 0 || x + y == target;
        }

        return target % gcd(x, y) == 0;
    }
};
// @lc code=end

// 扩展：使用 BFS 求解具体操作步骤
struct JugState
{
    int a;                      // 水壶 A 的水量
    int b;                      // 水壶 B 的水量
    int a_capacity, b_capacity; // 水壶 AB 的最大容量

    JugState() = default;

    JugState(int x, int y, int a_capacity, int b_capacity) : a(x), b(y), a_capacity(a_capacity), b_capacity(b_capacity) {};

    JugState fullA()
    {
        return JugState(a_capacity, b, a_capacity, b_capacity);
    }

    JugState fullB()
    {
        return JugState(a, b_capacity, a_capacity, b_capacity);
    }

    JugState emptyA()
    {
        return JugState(0, b, a_capacity, b_capacity);
    }

    JugState emptyB()
    {
        return JugState(a, 0, a_capacity, b_capacity);
    }

    JugState AtoB()
    {
        return JugState(a - min(a, b_capacity - b), b + min(a, b_capacity - b), a_capacity, b_capacity);
    }

    JugState BtoA()
    {
        return JugState(a + min(a_capacity - a, b), b - min(a_capacity - a, b), a_capacity, b_capacity);
    }

    bool reached(int target)
    {
        return a == target || b == target || a + b == target;
    }

    bool operator==(const JugState &other) const
    {
        return a == other.a && b == other.b;
    }
};

struct JugStateHasher
{
    std::size_t operator()(const JugState &s) const
    {
        return std::hash<int>{}(s.a) ^ (std::hash<int>{}(s.b) << 1);
    }
};

using JugStateMap = unordered_map<JugState, JugState, JugStateHasher>;

using JugStringMap = unordered_map<JugState, string, JugStateHasher>;

bool canMeasureWater(int x, int y, int target)
{
    if (x + y < target)
        return false;

    if (x == 0 || y == 0)
    {
        return target == 0 || x + y == target;
    }

    return target % gcd(x, y) == 0;
}

void tracebackPath(JugState &s, vector<pair<JugState, string>> &path, JugStateMap &history, JugStringMap &state_op_name)
{
    path.clear();

    while (s.a != -1 && s.b != -1)
    {
        path.push_back({s, state_op_name[s]});
        s = history[s];
    }
}

vector<pair<JugState, string>> bfsMeasureWater(int x, int y, int target)
{
    vector<pair<JugState, string>> path;

    if (!canMeasureWater(x, y, target))
        return path;

    JugState start(0, 0, x, y);

    auto jug_hash_fn = [](const JugState &s)
    {
        return hash<int>()(s.a) ^ hash<int>()(s.b);
    };

    JugStateMap history;
    history[start] = {-1, -1, x, y};

    JugStringMap state_op_name;
    state_op_name[start] = "初始状态";

    if (start.reached(target))
    {
        path.push_back({start, state_op_name[start]});
        return path;
    }

    queue<JugState> qu;
    qu.push(start);

    while (!qu.empty())
    {
        JugState s = qu.front();
        qu.pop();

        // 装满壶 A
        JugState next_state = s.fullA();
        if (history.find(next_state) == history.end())
        {
            history[next_state] = s;
            state_op_name[next_state] = "装满壶A";
            if (next_state.reached(target))
            {
                tracebackPath(next_state, path, history, state_op_name);
                return path;
            }
            qu.push(next_state);
        }

        // 装满壶 B
        next_state = s.fullB();
        if (history.find(next_state) == history.end())
        {
            history[next_state] = s;
            state_op_name[next_state] = "装满壶B";
            if (next_state.reached(target))
            {
                tracebackPath(next_state, path, history, state_op_name);
                return path;
            }
            qu.push(next_state);
        }

        // 清空壶 A
        next_state = s.emptyA();
        if (history.find(next_state) == history.end())
        {
            history[next_state] = s;
            state_op_name[next_state] = "清空壶A";
            if (next_state.reached(target))
            {
                tracebackPath(next_state, path, history, state_op_name);
                return path;
            }
            qu.push(next_state);
        }

        // 清空壶 B
        next_state = s.emptyB();
        if (history.find(next_state) == history.end())
        {
            history[next_state] = s;
            state_op_name[next_state] = "清空壶B";
            if (next_state.reached(target))
            {
                tracebackPath(next_state, path, history, state_op_name);
                return path;
            }
            qu.push(next_state);
        }

        // 将壶 A 倒入壶 B
        next_state = s.AtoB();
        if (history.find(next_state) == history.end())
        {
            history[next_state] = s;
            state_op_name[next_state] = "将壶A倒入壶B";
            if (next_state.reached(target))
            {
                tracebackPath(next_state, path, history, state_op_name);
                return path;
            }
            qu.push(next_state);
        }

        // 将壶 B 倒入壶 A
        next_state = s.BtoA();
        if (history.find(next_state) == history.end())
        {
            history[next_state] = s;
            state_op_name[next_state] = "将壶B倒入壶A";
            if (next_state.reached(target))
            {
                tracebackPath(next_state, path, history, state_op_name);
                return path;
            }
            qu.push(next_state);
        }
    }

    return path;
}

void printPath(vector<pair<JugState, string>> &path, int x, int y, int target)
{
    cout << "水壶容量: A=" << x << "L, B=" << y << "L, 目标=" << target << "L." << endl;
    if (path.size() == 0)
    {
        cout << "无法完成." << endl;
        return;
    }

    std::reverse(path.begin(), path.end());

    cout << "步骤    操作    壶A水量    壶B水量" << endl;
    for (int i = 0; i < path.size(); i++)
    {
        auto [state, name] = path[i];
        cout << i << " " << name << " " << " " << state.a << " " << state.b << endl;
    }
}

// int main()
// {
//     vector<vector<int>> test_cases = {
//         {3, 5, 8},
//         {3, 5, 4},
//         {2, 6, 4}};

//     for (auto tc : test_cases)
//     {
//         vector<pair<JugState, string>> path = bfsMeasureWater(tc[0], tc[1], tc[2]);
//         printPath(path, tc[0], tc[1], tc[2]);
//         cout << "\n";
//     }

//     std::string input;

//     while (true) {
//         std::cout << "请输入三个正整数（输入 'exit' 退出）:" << std::endl;
//         std::vector<int> nums;
//         bool shouldExit = false;

//         // 循环读取三个输入项
//         for (int i = 0; i < 3; ++i) {
//             if (!(std::cin >> input)) return 0; // 处理 EOF

//             if (input == "exit") {
//                 shouldExit = true;
//                 break;
//             }

//             try {
//                 // 将字符串转换为整数
//                 int n = std::stoi(input);
//                 nums.push_back(n);
//             } catch (...) {
//                 std::cout << "错误：请输入有效的整数或 'exit'。" << std::endl;
//                 // 清除当前错误的输入行，防止死循环（简单处理可以直接 break 或 continue）
//                 i--; 
//             }
//         }

//         if (shouldExit) break;

//         // 成功获取三个数字后的逻辑
//         if (nums.size() == 3) {
//             std::cout << "收到数字: " << nums[0] << ", " << nums[1] << ", " << nums[2] << std::endl;
//             vector<pair<JugState, string>> path = bfsMeasureWater(nums[0], nums[1], nums[2]);
//             printPath(path, nums[0], nums[1], nums[2]);
//             cout << "\n";
//         }
//     }

//     std::cout << "程序已退出。" << std::endl;
//     return 0;
// }