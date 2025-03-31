#include <grpcpp/grpcpp.h>
#include "service.grpc.pb.h"
#include <iostream>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using Mini2::DataService;
using Mini2::DataRequest;
using Mini2::DataResponse;

class DataServiceImpl final : public DataService::Service {
    Status SendData(ServerContext* context, const DataRequest* request, DataResponse* response) override {
        std::cout << "Server A received data: " << request->data() << std::endl;
        response->set_message("Data received by Server A");
        return Status::OK;
    }
};

int main() {
    std::string server_address("0.0.0.0:50051");
    DataServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server A listening on " << server_address << std::endl;

    server->Wait();
    return 0;
}
