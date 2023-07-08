/**
 * GDatum Cloud Platform
 *
 * Copyright (C) kbCrafted - All Rights Reserved
 * Copyright (C) liva Ramarolahy <liva.ramarolahy@gmail.com>
 *
 * Licensed under the MIT License
 */

#ifndef GDATUM_CORE_TASK_SCHEDULER_H
#define GDATUM_CORE_TASK_SCHEDULER_H

#include "task.h"

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <memory>
#include <vector>

namespace gdatum::core {
    class TaskScheduler : boost::noncopyable {
        boost::asio::io_service io_service;
        std::vector<std::shared_ptr<Task>> tasks;

    public:
        void add_task(const std::shared_ptr<Task>&);

        void run();

        void stop();

        boost::asio::io_service &get_service_ref();
    };
}


#endif //GDATUM_CORE_TASK_SCHEDULER_H
