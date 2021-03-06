package RESTapp;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class Customer {
	private String id;
	private String name;
	private String address;
	private String phoneNumber;
	private String email;

	public Customer() {
	}

	public Customer(String id) {
		this.id = id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getEmail() {
		return email;
	}

	public String getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public String getPhoneNumber() {
		return phoneNumber;
	}

	public String getAddress() {
		return address;
	}
}