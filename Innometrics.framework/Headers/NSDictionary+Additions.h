//
//  NSMutableDictionary+Additions.h
//  Innometrics
//
//  Created by Fedor Pudeyan on 27/04/15.
//  Copyright (c) 2015 Innometrics AB. All rights reserved.
//

@interface NSDictionary (Additions)

+ (NSDictionary *) dictionaryByMerging: (NSDictionary *) dict1 with: (NSDictionary *) dict2;
- (NSDictionary *) dictionaryByMergingWith: (NSDictionary *) dict;

+ (NSDictionary *)dictionaryWithData:(NSData *)data;
- (NSData *)data;

@end
