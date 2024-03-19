#include "Context.h"
#include <fstream>
#include <iostream>
#include <sstream>
namespace wg
{
struct Point
{
    int    id;
    double latitude;
    double longitude;
    int    elevation;

    Point(int id, double latitude, double longitude, int elevation)
        : id(id)
        , latitude(latitude)
        , longitude(longitude)
        , elevation(elevation)
    {}
};
void GenerateDJIWaypoints(const boost::filesystem::path& intput,
                                const boost::filesystem::path& output)
{
    std::string        filePath = intput.string();   // 替换为实际文件路径
    std::ifstream      file(filePath);
    std::vector<Point> points;

    if (!file.is_open()) {
        std::cerr << "无法打开文件：" << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int                id, elevation;
        double             latitude, longitude;
        std::string              token;
        std::vector<std::string> tokens;

        // 使用逗号作为分隔符读取每个字段
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        // 转换并保存数据
        if (tokens.size() == 4) {   // 确保每行有4个字段
            int    id        = std::stoi(tokens[0]);
            double latitude  = std::stod(tokens[1]);
            double longitude = std::stod(tokens[2]);
            int    elevation = std::stoi(tokens[3]);

            points.push_back(Point(id, latitude, longitude, elevation));
        }
    }

    file.close();   // 关闭文件

    // 输出读取的数据，确认是否正确
    for (const auto& point : points) {
        std::cout << "ID: " << point.id << ", Latitude: " << point.latitude
                  << ", Longitude: " << point.longitude << ", Elevation: " << point.elevation
                  << std::endl;
    }
}

}