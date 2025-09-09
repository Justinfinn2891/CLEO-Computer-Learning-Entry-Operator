# CLEO - Computer Learning Educational Operator

Project Tracker -> https://docs.google.com/spreadsheets/d/12y3wJU4cHn6q5bq1VsLETFq5kpCxoWj3vPIzxyNg8aM/edit?usp=sharing
g++ lidar.cpp -o mylidar -I./rplidar_sdk-master/sdk/include -I./rplidar_sdk-master/sdk/src ./rplidar_sdk-master/output/Linux/Release/libsl_lidar_sdk.a
/usr/bin/ld: cannot find ./rplidar_sdk-master/output/Linux/Release/libsl_lidar_sdk.a: No such file or directory
collect2: error: ld returned 1 exit status
Guys we need to a git ignore file 

its now leo :( lidar entry operator



g++ lidar.cpp -o mylidar -I./rplidar_sdk-master/sdk/include -I./rplidar_sdk-master/sdk/src ~/rplidar_sdk-maste
r/output/Linux/Release/libsl_lidar_sdk.a
/usr/bin/ld: /tmp/ccHum8mq.o: in function `main':
lidar.cpp:(.text+0x54): undefined reference to `rp::standalone::rplidar::RPlidarDriver::CreateDriver(unsigned int)'
/usr/bin/ld: lidar.cpp:(.text+0xc0): undefined reference to `rp::standalone::rplidar::RPlidarDriver::connect(char const*, unsigned int, unsigned int)'
/usr/bin/ld: lidar.cpp:(.text+0x128): undefined reference to `rp::standalone::rplidar::RPlidarDriver::startMotor()'
/usr/bin/ld: lidar.cpp:(.text+0x144): undefined reference to `rp::standalone::rplidar::RPlidarDriver::startScan(bool, bool, unsigned int, sl::LidarScanMode*)'
/usr/bin/ld: lidar.cpp:(.text+0x1a4): undefined reference to `rp::standalone::rplidar::RPlidarDriver::grabScanDataHq(sl_lidar_response_measurement_node_hq_t*, unsigned long&, unsigned int)'
/usr/bin/ld: lidar.cpp:(.text+0x1e0): undefined reference to `rp::standalone::rplidar::RPlidarDriver::ascendScanData(sl_lidar_response_measurement_node_hq_t*, unsigned long)'
/usr/bin/ld: lidar.cpp:(.text+0x3b8): undefined reference to `rp::standalone::rplidar::RPlidarDriver::stop(unsigned int)'
/usr/bin/ld: lidar.cpp:(.text+0x3c4): undefined reference to `rp::standalone::rplidar::RPlidarDriver::stopMotor()'
/usr/bin/ld: lidar.cpp:(.text+0x3d0): undefined reference to `rp::standalone::rplidar::RPlidarDriver::DisposeDriver(rp::standalone::rplidar::RPlidarDriver*)'
collect2: error: ld returned 1 exit status



/usr/bin/ld: CMakeFiles/mylidar.dir/rplidar_sdk-master/sdk/src/sl_lidar_driver.cpp.o: in function `sl::SlamtecLidarDriver::SlamtecLidarDriver()':
sl_lidar_driver.cpp:(.text._ZN2sl18SlamtecLidarDriverC2Ev[_ZN2sl18SlamtecLidarDriverC5Ev]+0x170): undefined reference to `sl::internal::LIDARSampleDataUnpacker::CreateInstance(sl::internal::LIDARSampleDataListener&)'
/usr/bin/ld: CMakeFiles/mylidar.dir/rplidar_sdk-master/sdk/src/sl_lidar_driver.cpp.o: in function `sl::SlamtecLidarDriver::negotiateSerialBaudRate(unsigned int, unsigned int*)':
sl_lidar_driver.cpp:(.text._ZN2sl18SlamtecLidarDriver23negotiateSerialBaudRateEjPj[_ZN2sl18SlamtecLidarDriver23negotiateSerialBaudRateEjPj]+0x140): undefined reference to `rp::arch::rp_getms()'
/usr/bin/ld: sl_lidar_driver.cpp:(.text._ZN2sl18SlamtecLidarDriver23negotiateSerialBaudRateEjPj[_ZN2sl18SlamtecLidarDriver23negotiateSerialBaudRateEjPj]+0x1cc): undefined reference to `rp::arch::rp_getms()'
/usr/bin/ld: CMakeFiles/mylidar.dir/rplidar_sdk-master/sdk/src/sl_serial_channel.cpp.o: in function `sl::SerialPortChannel::SerialPortChannel(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int)':
sl_serial_channel.cpp:(.text._ZN2sl17SerialPortChannelC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl17SerialPortChannelC5ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x30): undefined reference to `rp::hal::serial_rxtx::CreateRxTx()'
/usr/bin/ld: CMakeFiles/mylidar.dir/rplidar_sdk-master/sdk/src/sl_tcp_channel.cpp.o: in function `sl::TcpChannel::TcpChannel(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int)':
sl_tcp_channel.cpp:(.text._ZN2sl10TcpChannelC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10TcpChannelC5ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x34): undefined reference to `rp::net::StreamSocket::CreateSocket(rp::net::SocketBase::socket_family_t)'
/usr/bin/ld: sl_tcp_channel.cpp:(.text._ZN2sl10TcpChannelC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10TcpChannelC5ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x4c): undefined reference to `rp::net::SocketAddress::SocketAddress()'
/usr/bin/ld: sl_tcp_channel.cpp:(.text._ZN2sl10TcpChannelC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10TcpChannelC5ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x94): undefined reference to `rp::net::SocketAddress::~SocketAddress()'
/usr/bin/ld: CMakeFiles/mylidar.dir/rplidar_sdk-master/sdk/src/sl_tcp_channel.cpp.o: in function `sl::TcpChannel::bind(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int)':
sl_tcp_channel.cpp:(.text._ZN2sl10TcpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10TcpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x38): undefined reference to `rp::net::SocketAddress::SocketAddress(char const*, int, rp::net::SocketAddress::address_type_t)'
/usr/bin/ld: sl_tcp_channel.cpp:(.text._ZN2sl10TcpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10TcpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x48): undefined reference to `rp::net::SocketAddress::operator=(rp::net::SocketAddress const&)'
/usr/bin/ld: sl_tcp_channel.cpp:(.text._ZN2sl10TcpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10TcpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x50): undefined reference to `rp::net::SocketAddress::~SocketAddress()'
/usr/bin/ld: sl_tcp_channel.cpp:(.text._ZN2sl10TcpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10TcpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x64): undefined reference to `rp::net::SocketAddress::~SocketAddress()'
/usr/bin/ld: CMakeFiles/mylidar.dir/rplidar_sdk-master/sdk/src/sl_tcp_channel.cpp.o: in function `sl::TcpChannel::~TcpChannel()':
sl_tcp_channel.cpp:(.text._ZN2sl10TcpChannelD2Ev[_ZN2sl10TcpChannelD5Ev]+0x30): undefined reference to `rp::net::SocketAddress::~SocketAddress()'
/usr/bin/ld: CMakeFiles/mylidar.dir/rplidar_sdk-master/sdk/src/sl_udp_channel.cpp.o: in function `sl::UdpChannel::UdpChannel(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int)':
sl_udp_channel.cpp:(.text._ZN2sl10UdpChannelC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10UdpChannelC5ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x34): undefined reference to `rp::net::DGramSocket::CreateSocket(rp::net::SocketBase::socket_family_t)'
/usr/bin/ld: sl_udp_channel.cpp:(.text._ZN2sl10UdpChannelC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10UdpChannelC5ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x4c): undefined reference to `rp::net::SocketAddress::SocketAddress()'
/usr/bin/ld: sl_udp_channel.cpp:(.text._ZN2sl10UdpChannelC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10UdpChannelC5ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x94): undefined reference to `rp::net::SocketAddress::~SocketAddress()'
/usr/bin/ld: CMakeFiles/mylidar.dir/rplidar_sdk-master/sdk/src/sl_udp_channel.cpp.o: in function `sl::UdpChannel::bind(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int)':
sl_udp_channel.cpp:(.text._ZN2sl10UdpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10UdpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x38): undefined reference to `rp::net::SocketAddress::SocketAddress(char const*, int, rp::net::SocketAddress::address_type_t)'
/usr/bin/ld: sl_udp_channel.cpp:(.text._ZN2sl10UdpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10UdpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x48): undefined reference to `rp::net::SocketAddress::operator=(rp::net::SocketAddress const&)'
/usr/bin/ld: sl_udp_channel.cpp:(.text._ZN2sl10UdpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10UdpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x50): undefined reference to `rp::net::SocketAddress::~SocketAddress()'
/usr/bin/ld: sl_udp_channel.cpp:(.text._ZN2sl10UdpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi[_ZN2sl10UdpChannel4bindERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi]+0x64): undefined reference to `rp::net::SocketAddress::~SocketAddress()'
/usr/bin/ld: CMakeFiles/mylidar.dir/rplidar_sdk-master/sdk/src/sl_udp_channel.cpp.o: in function `sl::UdpChannel::~UdpChannel()':
sl_udp_channel.cpp:(.text._ZN2sl10UdpChannelD2Ev[_ZN2sl10UdpChannelD5Ev]+0x30): undefined reference to `rp::net::SocketAddress::~SocketAddress()'
collect2: error: ld returned 1 exit status
make[2]: *** [CMakeFiles/mylidar.dir/build.make:241: mylidar] Error 1
make[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/mylidar.dir/all] Error 2
