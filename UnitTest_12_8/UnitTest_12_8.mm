//
//  UnitTest_12_8.m
//  UnitTest_12_8
//
//  Created by USER on 17.05.2023.
//

#import "Header.h"
#import <XCTest/XCTest.h>

@interface UnitTest_12_8 : XCTestCase

@end

@implementation UnitTest_12_8

- (void)testExample {

    Node* head = nullptr;
    
    addNode(&head, "Hello");
    XCTAssert(head != nullptr);
    XCTAssert(head->prev == nullptr);
    XCTAssert(head->next == nullptr);
}



@end
