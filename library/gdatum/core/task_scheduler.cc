/**
 * GDatum Cloud Platform
 *
 * Copyright (C) kbCrafted - All Rights Reserved
 * Copyright (C) liva Ramarolahy <liva.ramarolahy@gmail.com>
 *
 * Licensed under the MIT License
 */

#include "task_scheduler.h"

namespace gdatum::core {
    void TaskScheduler::add_task(const std::shared_ptr<Task>& task) {
        tasks.push_back(task);
    }

    void TaskScheduler::run() { io_service.run(); }

    void TaskScheduler::stop() { io_service.stop(); }

    boost::asio::io_service &TaskScheduler::get_service_ref() {
        return std::ref(io_service);
    }
}