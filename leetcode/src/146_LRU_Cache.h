#pragma once

#include "heads.h"


struct LRUNode {
	int key;
	int value;
	LRUNode* prev;
	LRUNode* next;
	LRUNode() :key(0), value(0), prev(nullptr), next(nullptr) {}
};


class LRUCache {
public:
	int size;
	int capacity;
	LRUNode* head;
	LRUNode* tail;
	
	std::unordered_map<int, LRUNode*> m;

	LRUCache(int capacity) :capacity(capacity), size(0) {
		head = new LRUNode;
		tail = new LRUNode;
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		if (m.find(key) == m.end()) {
			return -1;
		}
		LRUNode* node = m[key];
		detachNode(node);
		insertNodeToFront(node);
		return node->value;
	}

	void put(int key, int value) {
		if (m.find(key) == m.end()) {
			LRUNode* node = new LRUNode;
			node->key = key;
			node->value = value;
			m[key] = node;
			insertNodeToFront(node);
			size++;
			if (size > capacity)
				delNode();
		}
		else {
			LRUNode* node = m[key];
			node->value = value;
			detachNode(node);
			insertNodeToFront(node);
		}
	}

	void detachNode(LRUNode* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node->prev = nullptr;
		node->next = nullptr;
	}

	void insertNodeToFront(LRUNode* node) {
		head->next->prev = node;
		node->next = head->next;
		head->next = node;
		node->prev = head;
	}

	void delNode() {
		LRUNode* node = tail->prev;
		detachNode(node);
		m.erase(node->key);
		size--;
		delete node;
	}

};