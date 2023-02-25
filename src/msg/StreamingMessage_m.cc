//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msg/StreamingMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "StreamingMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace ecsnetpp {

Register_Class(StreamingMessage)

StreamingMessage::StreamingMessage(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

StreamingMessage::StreamingMessage(const StreamingMessage& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

StreamingMessage::~StreamingMessage()
{
}

StreamingMessage& StreamingMessage::operator=(const StreamingMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void StreamingMessage::copy(const StreamingMessage& other)
{
    this->messageId = other.messageId;
    this->sender = other.sender;
    this->content = other.content;
    this->isProcessingDelayInCyclesPerEvent_ = other.isProcessingDelayInCyclesPerEvent_;
    this->processingDelayPerEvent = other.processingDelayPerEvent;
    this->selectivityRatio = other.selectivityRatio;
    this->startTime = other.startTime;
    this->operatorIngressTime = other.operatorIngressTime;
    this->channelIngressTime = other.channelIngressTime;
    this->networkDelay = other.networkDelay;
    this->processingDelay = other.processingDelay;
    this->edgeProcessingDelay = other.edgeProcessingDelay;
}

void StreamingMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->messageId);
    doParsimPacking(b,this->sender);
    doParsimPacking(b,this->content);
    doParsimPacking(b,this->isProcessingDelayInCyclesPerEvent_);
    doParsimPacking(b,this->processingDelayPerEvent);
    doParsimPacking(b,this->selectivityRatio);
    doParsimPacking(b,this->startTime);
    doParsimPacking(b,this->operatorIngressTime);
    doParsimPacking(b,this->channelIngressTime);
    doParsimPacking(b,this->networkDelay);
    doParsimPacking(b,this->processingDelay);
    doParsimPacking(b,this->edgeProcessingDelay);
}

void StreamingMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->messageId);
    doParsimUnpacking(b,this->sender);
    doParsimUnpacking(b,this->content);
    doParsimUnpacking(b,this->isProcessingDelayInCyclesPerEvent_);
    doParsimUnpacking(b,this->processingDelayPerEvent);
    doParsimUnpacking(b,this->selectivityRatio);
    doParsimUnpacking(b,this->startTime);
    doParsimUnpacking(b,this->operatorIngressTime);
    doParsimUnpacking(b,this->channelIngressTime);
    doParsimUnpacking(b,this->networkDelay);
    doParsimUnpacking(b,this->processingDelay);
    doParsimUnpacking(b,this->edgeProcessingDelay);
}

int StreamingMessage::getMessageId() const
{
    return this->messageId;
}

void StreamingMessage::setMessageId(int messageId)
{
    this->messageId = messageId;
}

const char * StreamingMessage::getSender() const
{
    return this->sender.c_str();
}

void StreamingMessage::setSender(const char * sender)
{
    this->sender = sender;
}

const char * StreamingMessage::getContent() const
{
    return this->content.c_str();
}

void StreamingMessage::setContent(const char * content)
{
    this->content = content;
}

bool StreamingMessage::isProcessingDelayInCyclesPerEvent() const
{
    return this->isProcessingDelayInCyclesPerEvent_;
}

void StreamingMessage::setIsProcessingDelayInCyclesPerEvent(bool isProcessingDelayInCyclesPerEvent)
{
    this->isProcessingDelayInCyclesPerEvent_ = isProcessingDelayInCyclesPerEvent;
}

double StreamingMessage::getProcessingDelayPerEvent() const
{
    return this->processingDelayPerEvent;
}

void StreamingMessage::setProcessingDelayPerEvent(double processingDelayPerEvent)
{
    this->processingDelayPerEvent = processingDelayPerEvent;
}

double StreamingMessage::getSelectivityRatio() const
{
    return this->selectivityRatio;
}

void StreamingMessage::setSelectivityRatio(double selectivityRatio)
{
    this->selectivityRatio = selectivityRatio;
}

::omnetpp::simtime_t StreamingMessage::getStartTime() const
{
    return this->startTime;
}

void StreamingMessage::setStartTime(::omnetpp::simtime_t startTime)
{
    this->startTime = startTime;
}

::omnetpp::simtime_t StreamingMessage::getOperatorIngressTime() const
{
    return this->operatorIngressTime;
}

void StreamingMessage::setOperatorIngressTime(::omnetpp::simtime_t operatorIngressTime)
{
    this->operatorIngressTime = operatorIngressTime;
}

::omnetpp::simtime_t StreamingMessage::getChannelIngressTime() const
{
    return this->channelIngressTime;
}

void StreamingMessage::setChannelIngressTime(::omnetpp::simtime_t channelIngressTime)
{
    this->channelIngressTime = channelIngressTime;
}

double StreamingMessage::getNetworkDelay() const
{
    return this->networkDelay;
}

void StreamingMessage::setNetworkDelay(double networkDelay)
{
    this->networkDelay = networkDelay;
}

double StreamingMessage::getProcessingDelay() const
{
    return this->processingDelay;
}

void StreamingMessage::setProcessingDelay(double processingDelay)
{
    this->processingDelay = processingDelay;
}

double StreamingMessage::getEdgeProcessingDelay() const
{
    return this->edgeProcessingDelay;
}

void StreamingMessage::setEdgeProcessingDelay(double edgeProcessingDelay)
{
    this->edgeProcessingDelay = edgeProcessingDelay;
}

class StreamingMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_messageId,
        FIELD_sender,
        FIELD_content,
        FIELD_isProcessingDelayInCyclesPerEvent,
        FIELD_processingDelayPerEvent,
        FIELD_selectivityRatio,
        FIELD_startTime,
        FIELD_operatorIngressTime,
        FIELD_channelIngressTime,
        FIELD_networkDelay,
        FIELD_processingDelay,
        FIELD_edgeProcessingDelay,
    };
  public:
    StreamingMessageDescriptor();
    virtual ~StreamingMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(StreamingMessageDescriptor)

StreamingMessageDescriptor::StreamingMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ecsnetpp::StreamingMessage)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

StreamingMessageDescriptor::~StreamingMessageDescriptor()
{
    delete[] propertyNames;
}

bool StreamingMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<StreamingMessage *>(obj)!=nullptr;
}

const char **StreamingMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *StreamingMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int StreamingMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 12+base->getFieldCount() : 12;
}

unsigned int StreamingMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_messageId
        FD_ISEDITABLE,    // FIELD_sender
        FD_ISEDITABLE,    // FIELD_content
        FD_ISEDITABLE,    // FIELD_isProcessingDelayInCyclesPerEvent
        FD_ISEDITABLE,    // FIELD_processingDelayPerEvent
        FD_ISEDITABLE,    // FIELD_selectivityRatio
        FD_ISEDITABLE,    // FIELD_startTime
        FD_ISEDITABLE,    // FIELD_operatorIngressTime
        FD_ISEDITABLE,    // FIELD_channelIngressTime
        FD_ISEDITABLE,    // FIELD_networkDelay
        FD_ISEDITABLE,    // FIELD_processingDelay
        FD_ISEDITABLE,    // FIELD_edgeProcessingDelay
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *StreamingMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageId",
        "sender",
        "content",
        "isProcessingDelayInCyclesPerEvent",
        "processingDelayPerEvent",
        "selectivityRatio",
        "startTime",
        "operatorIngressTime",
        "channelIngressTime",
        "networkDelay",
        "processingDelay",
        "edgeProcessingDelay",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int StreamingMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "messageId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sender") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "content") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "isProcessingDelayInCyclesPerEvent") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "processingDelayPerEvent") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "selectivityRatio") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "startTime") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "operatorIngressTime") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "channelIngressTime") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "networkDelay") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "processingDelay") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "edgeProcessingDelay") == 0) return baseIndex + 11;
    return base ? base->findField(fieldName) : -1;
}

const char *StreamingMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_messageId
        "string",    // FIELD_sender
        "string",    // FIELD_content
        "bool",    // FIELD_isProcessingDelayInCyclesPerEvent
        "double",    // FIELD_processingDelayPerEvent
        "double",    // FIELD_selectivityRatio
        "omnetpp::simtime_t",    // FIELD_startTime
        "omnetpp::simtime_t",    // FIELD_operatorIngressTime
        "omnetpp::simtime_t",    // FIELD_channelIngressTime
        "double",    // FIELD_networkDelay
        "double",    // FIELD_processingDelay
        "double",    // FIELD_edgeProcessingDelay
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **StreamingMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *StreamingMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int StreamingMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    StreamingMessage *pp = omnetpp::fromAnyPtr<StreamingMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void StreamingMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    StreamingMessage *pp = omnetpp::fromAnyPtr<StreamingMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'StreamingMessage'", field);
    }
}

const char *StreamingMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    StreamingMessage *pp = omnetpp::fromAnyPtr<StreamingMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string StreamingMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    StreamingMessage *pp = omnetpp::fromAnyPtr<StreamingMessage>(object); (void)pp;
    switch (field) {
        case FIELD_messageId: return long2string(pp->getMessageId());
        case FIELD_sender: return oppstring2string(pp->getSender());
        case FIELD_content: return oppstring2string(pp->getContent());
        case FIELD_isProcessingDelayInCyclesPerEvent: return bool2string(pp->isProcessingDelayInCyclesPerEvent());
        case FIELD_processingDelayPerEvent: return double2string(pp->getProcessingDelayPerEvent());
        case FIELD_selectivityRatio: return double2string(pp->getSelectivityRatio());
        case FIELD_startTime: return simtime2string(pp->getStartTime());
        case FIELD_operatorIngressTime: return simtime2string(pp->getOperatorIngressTime());
        case FIELD_channelIngressTime: return simtime2string(pp->getChannelIngressTime());
        case FIELD_networkDelay: return double2string(pp->getNetworkDelay());
        case FIELD_processingDelay: return double2string(pp->getProcessingDelay());
        case FIELD_edgeProcessingDelay: return double2string(pp->getEdgeProcessingDelay());
        default: return "";
    }
}

void StreamingMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    StreamingMessage *pp = omnetpp::fromAnyPtr<StreamingMessage>(object); (void)pp;
    switch (field) {
        case FIELD_messageId: pp->setMessageId(string2long(value)); break;
        case FIELD_sender: pp->setSender((value)); break;
        case FIELD_content: pp->setContent((value)); break;
        case FIELD_isProcessingDelayInCyclesPerEvent: pp->setIsProcessingDelayInCyclesPerEvent(string2bool(value)); break;
        case FIELD_processingDelayPerEvent: pp->setProcessingDelayPerEvent(string2double(value)); break;
        case FIELD_selectivityRatio: pp->setSelectivityRatio(string2double(value)); break;
        case FIELD_startTime: pp->setStartTime(string2simtime(value)); break;
        case FIELD_operatorIngressTime: pp->setOperatorIngressTime(string2simtime(value)); break;
        case FIELD_channelIngressTime: pp->setChannelIngressTime(string2simtime(value)); break;
        case FIELD_networkDelay: pp->setNetworkDelay(string2double(value)); break;
        case FIELD_processingDelay: pp->setProcessingDelay(string2double(value)); break;
        case FIELD_edgeProcessingDelay: pp->setEdgeProcessingDelay(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StreamingMessage'", field);
    }
}

omnetpp::cValue StreamingMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    StreamingMessage *pp = omnetpp::fromAnyPtr<StreamingMessage>(object); (void)pp;
    switch (field) {
        case FIELD_messageId: return pp->getMessageId();
        case FIELD_sender: return pp->getSender();
        case FIELD_content: return pp->getContent();
        case FIELD_isProcessingDelayInCyclesPerEvent: return pp->isProcessingDelayInCyclesPerEvent();
        case FIELD_processingDelayPerEvent: return pp->getProcessingDelayPerEvent();
        case FIELD_selectivityRatio: return pp->getSelectivityRatio();
        case FIELD_startTime: return pp->getStartTime().dbl();
        case FIELD_operatorIngressTime: return pp->getOperatorIngressTime().dbl();
        case FIELD_channelIngressTime: return pp->getChannelIngressTime().dbl();
        case FIELD_networkDelay: return pp->getNetworkDelay();
        case FIELD_processingDelay: return pp->getProcessingDelay();
        case FIELD_edgeProcessingDelay: return pp->getEdgeProcessingDelay();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'StreamingMessage' as cValue -- field index out of range?", field);
    }
}

void StreamingMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    StreamingMessage *pp = omnetpp::fromAnyPtr<StreamingMessage>(object); (void)pp;
    switch (field) {
        case FIELD_messageId: pp->setMessageId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sender: pp->setSender(value.stringValue()); break;
        case FIELD_content: pp->setContent(value.stringValue()); break;
        case FIELD_isProcessingDelayInCyclesPerEvent: pp->setIsProcessingDelayInCyclesPerEvent(value.boolValue()); break;
        case FIELD_processingDelayPerEvent: pp->setProcessingDelayPerEvent(value.doubleValue()); break;
        case FIELD_selectivityRatio: pp->setSelectivityRatio(value.doubleValue()); break;
        case FIELD_startTime: pp->setStartTime(value.doubleValue()); break;
        case FIELD_operatorIngressTime: pp->setOperatorIngressTime(value.doubleValue()); break;
        case FIELD_channelIngressTime: pp->setChannelIngressTime(value.doubleValue()); break;
        case FIELD_networkDelay: pp->setNetworkDelay(value.doubleValue()); break;
        case FIELD_processingDelay: pp->setProcessingDelay(value.doubleValue()); break;
        case FIELD_edgeProcessingDelay: pp->setEdgeProcessingDelay(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StreamingMessage'", field);
    }
}

const char *StreamingMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr StreamingMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    StreamingMessage *pp = omnetpp::fromAnyPtr<StreamingMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void StreamingMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    StreamingMessage *pp = omnetpp::fromAnyPtr<StreamingMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StreamingMessage'", field);
    }
}

}  // namespace ecsnetpp

namespace omnetpp {

}  // namespace omnetpp

