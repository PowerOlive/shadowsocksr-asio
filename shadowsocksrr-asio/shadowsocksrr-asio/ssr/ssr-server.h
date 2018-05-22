/*
 *  This file is part of the shadowsocksrr-asio project.
 *  shadowsocksrr-asio is a shadowsocksr implement which driven by boost.asio.
 *  Copyright (C) 2018  Akkariiin
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SSR_SERVER_H
#define SSR_SERVER_H
#include <boost/asio.hpp>
#include <memory>
#include "../base-server.h"
#include "ssr-config.h"

// forward declaration to break include loop reference
class SsrUdpBase;

class SsrServer : public BaseServer
{
private:
	std::shared_ptr<SsrConfig> ssr_config_;

	boost::asio::ip::tcp::endpoint listen_endpoint_;
	std::unique_ptr<boost::asio::ip::tcp::acceptor> tcp_acceptor_;

	std::shared_ptr<SsrUdpBase> ssr_udp_relay_;

public:
	enum Mode
	{
		SERVER,
		CLIENT,
	};
private:
	Mode mode;
public:
	SsrServer(std::shared_ptr<MainConfig> config, std::shared_ptr<SsrConfig> ssr_config, boost::asio::io_service& io_service);
	void run() override;

private:
	void async_accept();
};




#endif	// SSR_SERVER_H
