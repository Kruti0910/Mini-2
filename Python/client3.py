import grpc
import service_pb2
import service_pb2_grpc

def run():
    channel = grpc.insecure_channel('localhost:50051')
    stub = service_pb2_grpc.DataServiceStub(channel)
    response = stub.SendData(service_pb2.DataRequest(data="Hello from Client 3"))
    print(f"Response from Server A: {response.message}")

if __name__ == "__main__":
    run()
