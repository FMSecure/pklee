//===-- EventTypes.h -------------------------------------------*- C++ -*-===//
//
//                     The KLEE Symbolic Virtual Machine
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef KLEE_EVENTTYPES_H
#define KLEE_EVENTTYPES_H


/** @enum EventType
 *  @brief Types of events to subscribe to, when calculating path priority
 *
 *  | Value                       | Description                                                         |
 *  |-----------------------------|---------------------------------------------------------------------|
 *  | `EventType::Any`            | every write operations, including rewriting the same value          |
 *  | `EventType::Change`         | only write operations that change the value of that memory address  |
 *  | `EventType::VerilogChange`  | only write operations that change the value of that memory address  |
 */
enum EventType {
  // Any write operation to that memory
  Any = 0,

  // Write operations where the new value (last element) is different that the
  // old value (last element - 1)
  Change,
};

#endif // KLEE_EVENTTYPES_H
