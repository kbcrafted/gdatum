/**
 * GDatum Cloud Platform
 *
 * Copyright (C) kbCrafted - All Rights Reserved
 * Copyright (C) liva Ramarolahy <liva.ramarolahy@gmail.com>
 *
 * Licensed under the MIT License
 */
#include "task.h"

#include <utility>

namespace gdatum::core {

    Task::Task(boost::asio::io_service &io_service, std::string name,
               int interval)
            : io_service(io_service), timer(io_service), name(std::move(name)),
              interval(interval) {
        io_service.post([this] { start(); });
    }

    void Task::execute(boost::system::error_code const &error_code) {
        if (error_code != boost::asio::error::operation_aborted) {
            process();
            timer.expires_at(timer.expires_at() +
                             boost::posix_time::seconds(interval));
            start_wait();
        }
    }

    void Task::start() {
        /**
         * Uncomment if you want to call the handler on startup (i.e. at time 0)
         */
        process();

        timer.expires_from_now(boost::posix_time::seconds(interval));
        start_wait();
    }

    void Task::start_wait() {

        timer.async_wait([this](boost::system::error_code const &error_code)  {
            execute(error_code);
        });
    }
}