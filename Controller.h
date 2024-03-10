//
// Created by yuyuan on 2024/3/10.
//

#ifndef CODECRAFTSDK_CONTROLLER_H
#define CODECRAFTSDK_CONTROLLER_H
#include <vector>
#include "Algorithms.h"
struct Operation{
    int objector;    /// 对象指代：0, robot. 1, boat.
    int command;
    int id;
    int optionArg;
};

/**
 * @brief 总操作结构体vector
 * @code
 *      // 存入数据
 *      operations.push_back(struct Operation);
 * 结构体参数
 * @param objector 0, robot. 1, boat.
 * @param command For robot: 0, move. 1, get. 2, pull. For boat: 0, ship. 1, go.
 * @param id id of robot or boat.
 * @param optionArg For robot: 0, right. 1, left. 2, up. 3, down. For boat: the id of berth.
 * */
inline std::vector<Operation> operations;


void controller();

#endif //CODECRAFTSDK_CONTROLLER_H
