#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <iostream>
#include <algorithm>
#include <queue>

//#define PS_DEBUG

#ifdef PS_DEBUG
#include <chrono>
#include <thread>
#endif

/*
6 10
0 0 0 0 0 0 1 0 0 0
0 1 1 1 1 0 0 0 1 0
0 1 0 0 0 1 0 1 0 0
0 1 0 1 0 1 0 1 0 0
0 1 0 1 0 1 0 1 1 0
0 0 0 1 0 0 0 0 0 0
4 3 3
3 9 2

5 6 
0 0 0 0 0 0
0 1 1 0 1 0
0 1 0 0 0 0
0 0 1 1 1 0
1 0 0 0 0 0
4 2 3
1 6 2
*/

class Point {
public:
    int x;
    int y;
    inline Point(int x, int y) : x(x), y(y) {}
    inline auto operator==(const Point& p) const -> bool {
        return x == p.x && y == p.y;
    }
    inline auto operator!=(const Point& p) const -> bool {
        return !(*this == p);
    }
    inline auto operator+(const Point& p) const -> Point {
        return Point(x + p.x, y + p.y);
    }
};

enum class Direction : char {
    UP = 4,
    DOWN = 3,
    LEFT = 2,
    RIGHT = 1
};

class Transform {
public:
    Point position;
    Direction direction;
    Transform(Point position, Direction direction) : position(position), direction(direction) {}
    Transform(int x, int y, Direction direction) : position(x, y), direction(direction) {}
    inline auto operator==(const Transform& t) const -> bool {
        return position == t.position && direction == t.direction;
    }
};

class GridBfs {
private:
    int width;
    int height;
    std::vector<std::vector<int>> grid;
public:
    GridBfs(int width, int height, std::vector<std::vector<int>>& grid)
        : width(width), height(height), grid(std::move(grid)) { }
    inline auto bfs(Transform start, Transform end) -> int {
        std::queue<std::pair<Transform, int>> queue;
        grid[start.position.y][start.position.x] |= 1 << static_cast<int>(start.direction);
#ifdef PS_DEBUG
        grid_view_update();
#endif
        queue.push(std::make_pair(start, 0));
        while (!queue.empty()) {
            auto& current = queue.front();
            for (auto next : next_step(current.first)) {
                if (next == end)
                    return current.second + 1;
                queue.push(std::make_pair(next, current.second + 1));
            }
            queue.pop();
        }
        return -1;
    }
private:
    inline auto next_step(Transform transform) -> std::vector<Transform> {
        auto& point = transform.position;
        std::vector<Transform> result;
        auto push_if_not_visited_rotation = [&](Point pos, Direction direction) {
            if (((grid[pos.y][pos.x] >> static_cast<int>(direction)) & 1) == 0) {
                result.push_back(Transform(pos, direction));
                grid[pos.y][pos.x] |= 1 << static_cast<int>(direction);
#ifdef PS_DEBUG
                grid_view_update();
#endif
            }
        };
        auto push_if_valid = [&](Point p) -> bool {
            if (0 <= p.x && p.x < width
                && 0 <= p.y && p.y < height) {
                if ((grid[p.y][p.x] & 1) == 0) {
                    push_if_not_visited_rotation(p, transform.direction);
                    return true;
                }
                return false;
            }
            return false;
        };
        switch (transform.direction) {
        case Direction::UP:
            if (push_if_valid(point + Point(0, -1)))
                if (push_if_valid(point + Point(0, -2)))
                    push_if_valid(point + Point(0, -3));
            push_if_not_visited_rotation(point, Direction::RIGHT);
            push_if_not_visited_rotation(point, Direction::LEFT);
            break;
        case Direction::DOWN:
            if (push_if_valid(point + Point(0, 1)))
                if (push_if_valid(point + Point(0, 2)))
                    push_if_valid(point + Point(0, 3));
            push_if_not_visited_rotation(point, Direction::RIGHT);
            push_if_not_visited_rotation(point, Direction::LEFT);
            break;
        case Direction::LEFT:
            if (push_if_valid(point + Point(-1, 0)))
                if (push_if_valid(point + Point(-2, 0)))
                    push_if_valid(point + Point(-3, 0));
            push_if_not_visited_rotation(point, Direction::UP);
            push_if_not_visited_rotation(point, Direction::DOWN);
            break;
        case Direction::RIGHT:
            if (push_if_valid(point + Point(1, 0)))
                if (push_if_valid(point + Point(2, 0)))
                    push_if_valid(point + Point(3, 0));
            push_if_not_visited_rotation(point, Direction::UP);
            push_if_not_visited_rotation(point, Direction::DOWN);
            break;
        }
        return result;
    }
#ifdef PS_DEBUG
    inline auto grid_view_update() -> void {
        system("cls");
        for (auto i = 0; i < height; ++i) {
            for (auto j = 0; j < width; ++j) {
                auto c = ' ';
                if (grid[i][j] == 0b00001)
                    c = '@';
                else if ((grid[i][j] & 0b11110) != 0)
                    c = '*';
                std::cout << c << c;
            }
            std::cout << '\n';
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
#endif
};

auto main() -> int {
    int grid_width, grid_height;
    std::cin >> grid_height >> grid_width;
    std::vector<std::vector<int>> grid(grid_height, std::vector<int>(grid_width));
    for (int i = 0; i < grid_height; ++i)
        for (int j = 0; j < grid_width; ++j)
            std::cin >> grid[i][j];
    GridBfs grid_bfs(grid_width, grid_height, grid);
    int start_x, start_y, start_direction;
    int end_x, end_y, end_direction;
    std::cin >> start_y >> start_x >> start_direction;
    std::cin >> end_y >> end_x >> end_direction;
    if(start_y==end_y&&start_x==end_x&&start_direction==end_direction){
        std::cout<<0;
        return 0;
        }
    start_x -= 1;
    start_y -= 1;
    end_x -= 1;
    end_y -= 1;
    std::cout << grid_bfs.bfs(
        Transform(start_x, start_y, Direction(start_direction)),
        Transform(end_x, end_y, Direction(end_direction))
    );
    return 0;
}