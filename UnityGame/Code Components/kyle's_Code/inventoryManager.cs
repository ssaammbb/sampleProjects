using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class inventoryManager : MonoBehaviour
{

    inventorySlot[] inventorySlots;
    public GameObject hotBar;
    public GameObject inventory;
    public Camera canvasCamera;
    public LayerMask Inventory;
    public LayerMask basicUI;
    bool inInventory=false;


    void Start()
    {
        inventorySlots = new inventorySlot[hotBar.transform.childCount+ inventory.transform.childCount];
        int i = 0;
        for(i = 0; i < hotBar.transform.childCount; i++)
        {
            inventorySlots[i].panel = hotBar.transform.GetChild(i).gameObject;
        }
        for (; i < inventory.transform.childCount+ hotBar.transform.childCount; i++)
        {
            inventorySlots[i].panel = inventory.transform.GetChild(i- hotBar.transform.childCount).gameObject;
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetButtonDown("Open Inventory"))
        {
            if (inInventory)
            {
                inInventory = false;
                canvasCamera.cullingMask = basicUI;
            }
            else
            {
                inInventory = true;
                canvasCamera.cullingMask = Inventory;
            }
        }
        if (Input.GetKeyDown("n"))
        {
            
            SceneManager.LoadScene(1);
        }
    }
    public bool addObject(GameObject objectItem)
    {
        item item = objectItem.GetComponent<item>();
        for (int i = 0; i < inventorySlots.Length; i++) {
            if (inventorySlots[i].item != null)
            {
                if (item.uniqueName == inventorySlots[i].itemScript.uniqueName && item.maxstack> inventorySlots[i].amount)
                {
                    inventorySlot slot = inventorySlots[i];
                    slot.amount++;
                    inventorySlots[i] = slot;
                    inventorySlots[i].panel.GetComponentInChildren<Text>().text = slot.amount.ToString();
                    Destroy(objectItem);
                    return true;
                }
            }
        }
        for (int i = 0; i < inventorySlots.Length; i++)
        {
            if (inventorySlots[i].item == null)
            {
                inventorySlot slot = inventorySlots[i];
                slot.amount = 1;
                int j;
                for (j = 0; j < GameData.Instance.items.Length; j++)
                {
                    if (GameData.Instance.items[j].GetComponent<item>().uniqueName == item.uniqueName)
                    {
                        slot.itemId = j;
                        break;
                    }
                }
                if(j== GameData.Instance.items.Length)
                {
                    Debug.LogWarning("Object not found in GameData");
                    break;
                }
                Destroy(objectItem);

                GameObject text =inventorySlots[i].panel.transform.GetChild(1).gameObject;
                text.SetActive(true);
                text.GetComponent<Text>().text = slot.amount.ToString();

                GameObject UIObject = Instantiate(GameData.Instance.items[slot.itemId]);
                UIObject.transform.SetParent(slot.panel.transform.GetChild(0));
                UIObject.transform.localPosition = new Vector3(0, 0, 0);
                UIObject.transform.localEulerAngles=new Vector3(0,0,0);
                UIObject.transform.localScale = new Vector3(1, 1, 1);
                slot.item = UIObject;
                inventorySlots[i] = slot;
                if (i >= hotBar.transform.childCount)
                {
                    UIObject.layer = 10;
                }
                else
                {
                    UIObject.layer = 5;
                }
                return true;
            }
        }
     
        return false;
    }
    
    public struct inventorySlot
    {
        public GameObject item;

        public int itemId;

        public GameObject panel;
        public item itemScript{
            get {
                return item.GetComponent<item>();
            }

        }
        public int amount;
        public inventorySlot(GameObject _item,GameObject _panel, int _amount,int _itemId)
        {
            itemId = _itemId;
            item = _item;
            amount = _amount;
            panel = _panel;
        }
    }
}
