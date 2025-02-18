//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msg/Ack.msg.
//

#ifndef __ECSNETPP_ACK_M_H
#define __ECSNETPP_ACK_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif


namespace ecsnetpp {

class Ack;

}  // namespace ecsnetpp


namespace ecsnetpp {

/**
 * Class generated from <tt>msg/Ack.msg:21</tt> by opp_msgtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet Ack
 * {
 *     int ackedMessageId;
 *     string sender;
 * }
 * </pre>
 */
class Ack : public ::omnetpp::cPacket
{
  protected:
    int ackedMessageId = 0;
    ::omnetpp::opp_string sender;

  private:
    void copy(const Ack& other);

  protected:
    bool operator==(const Ack&) = delete;

  public:
    Ack(const char *name=nullptr, short kind=0);
    Ack(const Ack& other);
    virtual ~Ack();
    Ack& operator=(const Ack& other);
    virtual Ack *dup() const override {return new Ack(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getAckedMessageId() const;
    virtual void setAckedMessageId(int ackedMessageId);

    virtual const char * getSender() const;
    virtual void setSender(const char * sender);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ack& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ack& obj) {obj.parsimUnpack(b);}


}  // namespace ecsnetpp


namespace omnetpp {

template<> inline ecsnetpp::Ack *fromAnyPtr(any_ptr ptr) { return check_and_cast<ecsnetpp::Ack*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __ECSNETPP_ACK_M_H

