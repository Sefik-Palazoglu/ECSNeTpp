/*
 * Supervisor.h
 *
 *  Created on: Oct 24, 2017
 *      Author: gayashan
 */

#ifndef STASK_STREAMINGSUPERVISOR_H_
#define STASK_STREAMINGSUPERVISOR_H_

#include "omnetpp.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include "inet/transportlayer/contract/tcp/TcpSocket.h"
#include "inet/common/socket/SocketMap.h"

using namespace omnetpp;

namespace ecsnetpp {

class StreamingSupervisor: public cSimpleModule , public inet::TcpSocket::ICallback{

private:
    const char* cloudAddress;
    bool joinMulticastGroup;
    bool ackersEnabled;
    bool checkpointsEnabled;
    bool hasUdp;
    bool hasTcp;
    inet::UdpSocket udpSocket;
    inet::TcpSocket tcpSocket;
    inet::TcpSocket serverSocket;
    inet::SocketMap tcpSocketMap;
    cMessage *selfMsg = nullptr;
    cMessage *bindMsg = nullptr;
    cMessage *joinMCastMsg = nullptr;
    std::map<inet::L3Address, inet::TcpSocket *> destinationSocketMap;
    std::map<std::string, std::vector<std::string>> senderStaskCategoryToDownstreamNodeMap;
    std::map<std::string, std::vector<inet::L3Address>> senderStaskCategoryToDownstreamNodeIPMap;

    simtime_t startTime = -1;
    int count = 0;
    void processSelfMessage();
    void processUDPMessage(omnetpp::cMessage* msg);
    void processTCPMessage(omnetpp::cMessage* msg);

public:
    static simsignal_t sentPkSize;
    static simsignal_t completedMIPS;
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void processUDPPacket(cMessage *msg);
    void processUDPError(cMessage *error);
public:
    virtual ~StreamingSupervisor();
    virtual void addSTaskCategoryToDownstreamNodeMapping(
            std::string senderSTaskCategory,
            std::string downstreamNodeFullPath);
    virtual void addSTaskCategoryToDownstreamNodeMapping(
            std::string senderSTaskCategory,
            std::vector<std::string> downstreamNodeFullPaths);
    virtual void resolveDownstreamNodeIPs();
    virtual void socketDataArrived(int connId, void *yourPtr, cPacket *msg, bool urgent) override;
    virtual void socketFailure(int connId, void *yourPtr, int code) override;
};

}

#endif /* STASK_STREAMINGSUPERVISOR_H_ */
