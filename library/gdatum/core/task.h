/**
 * GDatum Cloud Platform
 *
 * Copyright (C) kbCrafted - All Rights Reserved
 * Copyright (C) liva Ramarolahy
 *
 * Licensed under the MIT License
 */

#ifndef GDATUM_CORE_TASK_H
#define GDATUM_CORE_TASK_H

#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>
#include <functional>

namespace gdatum::core {
    /**
     *
     */
    class Task : boost::noncopyable {
    public:
        /**
         *
         * @param io_service
         * @param name
         * @param interval
         */
        Task(boost::asio::io_service &io_service, std::string name, int interval);

        void execute(boost::system::error_code const &e);

        void start();

        virtual void process() = 0;

    private:
        boost::asio::io_service &io_service;

        boost::asio::deadline_timer timer;

        std::string name;

        int interval;

    private:
        void start_wait();
    };
}

#endif //GDATUM_CORE_TASK_H
