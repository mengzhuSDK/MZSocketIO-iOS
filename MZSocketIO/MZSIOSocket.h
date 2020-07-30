#import <Foundation/Foundation.h>

// NSArray of these JSValue-valid objects:
typedef NSArray SIOParameterArray;
// --------------------
//        NSNull       
//       NSString      
//       NSNumber      
//     NSDictionary    
//       NSArray       
//        NSData
// --------------------

@interface MZSIOSocket : NSObject

// Generators
+ (void)socketWithHost:(NSString *)hostURL Token:(NSString *)token response:(void(^)(MZSIOSocket *socket))response;
+ (void)socketWithHost:(NSString *)hostURL reconnectAutomatically:(BOOL)reconnectAutomatically attemptLimit:(NSInteger)attempts withDelay:(NSTimeInterval)reconnectionDelay maximumDelay:(NSTimeInterval)maximumDelay timeout:(NSTimeInterval)timeout Token:(NSString *)token response:(void(^)(MZSIOSocket *socket))response;
+ (void)socketWithHost:(NSString *)hostURL reconnectAutomatically:(BOOL)reconnectAutomatically attemptLimit:(NSInteger)attempts withDelay:(NSTimeInterval)reconnectionDelay maximumDelay:(NSTimeInterval)maximumDelay timeout:(NSTimeInterval)timeout withTransports:(NSArray *)transports Token:(NSString *)token response:(void(^)(MZSIOSocket *socket))response;

// Event responders
@property (nonatomic, copy) void (^onConnect)(void);
@property (nonatomic, copy) void (^onConnectError)(NSDictionary *errorInfo);
@property (nonatomic, copy) void (^onDisconnect)(void);
@property (nonatomic, copy) void (^onError)(NSDictionary *errorInfo);

@property (nonatomic, copy) void (^onReconnect)(NSInteger numberOfAttempts);
@property (nonatomic, copy) void (^onReconnectionAttempt)(NSInteger numberOfAttempts);
@property (nonatomic, copy) void (^onReconnectionError)(NSDictionary *errorInfo);

- (void)on:(NSString *)event callback:(void (^)(SIOParameterArray *args))function;

// Emitters
- (void)emit:(NSString *)event;
- (void)emit:(NSString *)event args:(SIOParameterArray *)args;

- (void)close;

@end
