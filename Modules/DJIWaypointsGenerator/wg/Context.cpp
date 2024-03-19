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
    std::string        filePath = intput.string();   // �滻Ϊʵ���ļ�·��
    std::ifstream      file(filePath);
    std::vector<Point> points;

    if (!file.is_open()) {
        std::cerr << "�޷����ļ���" << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int                id, elevation;
        double             latitude, longitude;
        std::string              token;
        std::vector<std::string> tokens;

        // ʹ�ö�����Ϊ�ָ�����ȡÿ���ֶ�
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        // ת������������
        if (tokens.size() == 4) {   // ȷ��ÿ����4���ֶ�
            int    id        = std::stoi(tokens[0]);
            double latitude  = std::stod(tokens[1]);
            double longitude = std::stod(tokens[2]);
            int    elevation = std::stoi(tokens[3]);

            points.push_back(Point(id, latitude, longitude, elevation));
        }
    }

    file.close();   // �ر��ļ�

    // �����ȡ�����ݣ�ȷ���Ƿ���ȷ
    for (const auto& point : points) {
        std::cout << "ID: " << point.id << ", Latitude: " << point.latitude
                  << ", Longitude: " << point.longitude << ", Elevation: " << point.elevation
                  << std::endl;
    }
}

}